//! Declarative terminal tutorials.
//!
//! Tutorial files describe ordinary comments, commands, and small literal
//! challenges.  This module deliberately knows nothing about terminals,
//! compiler semantics, or backend processes: the application hosts the pure
//! runner by applying its editor and submission actions.

use serde::Deserialize;
use std::collections::{BTreeMap, BTreeSet};
use std::fs;
use std::path::{Path, PathBuf};
use unicode_segmentation::UnicodeSegmentation;

pub const TUTORIAL_FORMAT: u32 = 1;
pub const TUTORIAL_TICK_MS: u64 = 20;

fn default_session() -> TutorialSession {
    TutorialSession::Fresh
}

fn default_wpm() -> [u16; 2] {
    [147, 173]
}

fn default_attempts() -> u16 {
    1
}

fn default_speed() -> u16 {
    100
}

#[derive(Clone, Copy, Debug, Deserialize, Eq, PartialEq)]
#[serde(rename_all = "kebab-case")]
pub enum TutorialSession {
    Fresh,
}

#[derive(Clone, Copy, Debug, Default, Deserialize, Eq, PartialEq)]
#[serde(rename_all = "kebab-case")]
pub enum ChallengeMatch {
    #[default]
    Exact,
    SlogRule,
}

#[derive(Clone, Copy, Debug, Default, Deserialize, Eq, PartialEq)]
#[serde(rename_all = "kebab-case")]
pub enum TutorialTypingMode {
    #[default]
    Natural,
    Code,
}

#[derive(Clone, Debug, Deserialize, Eq, PartialEq)]
#[serde(deny_unknown_fields)]
pub struct Tutorial {
    pub format: u32,
    pub id: String,
    pub title: String,
    pub summary: String,
    #[serde(default = "default_session")]
    pub session: TutorialSession,
    #[serde(default = "default_wpm")]
    pub typing_wpm: [u16; 2],
    #[serde(default)]
    pub effects: Vec<String>,
    pub steps: Vec<TutorialStep>,
}

#[derive(Clone, Debug, Deserialize, Eq, PartialEq)]
#[serde(tag = "type", rename_all = "kebab-case", deny_unknown_fields)]
pub enum TutorialStep {
    Comment {
        text: String,
        #[serde(default = "default_speed")]
        speed: u16,
    },
    Command {
        text: String,
        #[serde(default = "default_speed")]
        speed: u16,
        #[serde(default)]
        typing: TutorialTypingMode,
    },
    Challenge {
        prompt: String,
        answers: Vec<String>,
        fallback: String,
        #[serde(default = "default_attempts")]
        attempts: u16,
        #[serde(default, rename = "match")]
        answer_match: ChallengeMatch,
        #[serde(default = "default_speed")]
        speed: u16,
    },
    Checkpoint {
        text: String,
        #[serde(default = "default_speed")]
        speed: u16,
    },
}

impl TutorialStep {
    fn speed(&self) -> u16 {
        match self {
            Self::Comment { speed, .. }
            | Self::Command { speed, .. }
            | Self::Challenge { speed, .. }
            | Self::Checkpoint { speed, .. } => *speed,
        }
    }
}

impl Tutorial {
    pub fn parse(source: &str) -> Result<Self, String> {
        let tutorial: Self = toml::from_str(source).map_err(|error| error.to_string())?;
        tutorial.validate()?;
        Ok(tutorial)
    }

    fn validate(&self) -> Result<(), String> {
        if self.format != TUTORIAL_FORMAT {
            return Err(format!(
                "unsupported tutorial format {}; expected {TUTORIAL_FORMAT}",
                self.format
            ));
        }
        if self.id.is_empty()
            || !self.id.chars().all(|character| {
                character.is_ascii_lowercase() || character.is_ascii_digit() || character == '-'
            })
        {
            return Err("id must contain lowercase ASCII letters, digits, or hyphens".to_owned());
        }
        if self.title.trim().is_empty() {
            return Err("title must not be empty".to_owned());
        }
        if self.summary.trim().is_empty() {
            return Err("summary must not be empty".to_owned());
        }
        let [minimum, maximum] = self.typing_wpm;
        if minimum < 20 || maximum > 600 || minimum > maximum {
            return Err("typing_wpm must be an ascending range between 20 and 600".to_owned());
        }
        if self.steps.is_empty() {
            return Err("a tutorial must contain at least one step".to_owned());
        }
        for (index, step) in self.steps.iter().enumerate() {
            let invalid = |message: &str| format!("step {}: {message}", index + 1);
            if !(25..=400).contains(&step.speed()) {
                return Err(invalid("speed must be between 25 and 400 percent"));
            }
            match step {
                TutorialStep::Comment { text, .. } | TutorialStep::Checkpoint { text, .. } => {
                    if text.trim().is_empty() {
                        return Err(invalid("text must not be empty"));
                    }
                }
                TutorialStep::Command { text, .. } => {
                    validate_command(text).map_err(|message| invalid(&message))?;
                }
                TutorialStep::Challenge {
                    prompt,
                    answers,
                    fallback,
                    attempts,
                    answer_match,
                    ..
                } => {
                    if prompt.trim().is_empty() {
                        return Err(invalid("prompt must not be empty"));
                    }
                    if answers.is_empty() || answers.iter().any(|answer| answer.trim().is_empty()) {
                        return Err(invalid("answers must contain non-empty commands"));
                    }
                    for answer in answers {
                        validate_command(answer).map_err(|message| invalid(&message))?;
                        if *answer_match == ChallengeMatch::SlogRule
                            && parse_slog_rule(answer).is_none()
                        {
                            return Err(invalid(
                                "slog-rule answers must each contain one parseable rule",
                            ));
                        }
                    }
                    if *attempts == 0 {
                        return Err(invalid("attempts must be at least one"));
                    }
                    if !answers
                        .iter()
                        .any(|answer| answer.trim() == fallback.trim())
                    {
                        return Err(invalid("fallback must be one of answers"));
                    }
                }
            }
        }
        Ok(())
    }
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct TutorialLoadError {
    pub path: PathBuf,
    pub message: String,
}

#[derive(Clone, Debug, Default)]
pub struct TutorialCatalog {
    tutorials: Vec<Tutorial>,
    errors: Vec<TutorialLoadError>,
}

impl TutorialCatalog {
    pub fn from_tutorials(tutorials: Vec<Tutorial>) -> Self {
        Self {
            tutorials,
            errors: Vec::new(),
        }
    }

    pub fn load(directory: &Path) -> Self {
        let entries = match fs::read_dir(directory) {
            Ok(entries) => entries,
            Err(error) => {
                return Self {
                    tutorials: Vec::new(),
                    errors: vec![TutorialLoadError {
                        path: directory.to_owned(),
                        message: error.to_string(),
                    }],
                };
            }
        };
        let mut paths = entries
            .filter_map(Result::ok)
            .map(|entry| entry.path())
            .filter(|path| {
                path.extension()
                    .is_some_and(|extension| extension == "toml")
            })
            .collect::<Vec<_>>();
        paths.sort();

        let mut catalog = Self::default();
        let mut ids = BTreeSet::new();
        for path in paths {
            let tutorial = fs::read_to_string(&path)
                .map_err(|error| error.to_string())
                .and_then(|source| Tutorial::parse(&source));
            match tutorial {
                Ok(tutorial) if ids.insert(tutorial.id.clone()) => catalog.tutorials.push(tutorial),
                Ok(tutorial) => catalog.errors.push(TutorialLoadError {
                    path,
                    message: format!("duplicate tutorial id {}", tutorial.id),
                }),
                Err(message) => catalog.errors.push(TutorialLoadError { path, message }),
            }
        }
        catalog
    }

    pub fn tutorials(&self) -> &[Tutorial] {
        &self.tutorials
    }

    pub fn errors(&self) -> &[TutorialLoadError] {
        &self.errors
    }
}

#[derive(Clone, Debug)]
pub struct TutorialMenu {
    pub tutorials: Vec<Tutorial>,
    pub selected: usize,
    pub load_errors: usize,
}

impl TutorialMenu {
    pub fn new(catalog: &TutorialCatalog) -> Self {
        Self {
            tutorials: catalog.tutorials.clone(),
            selected: 0,
            load_errors: catalog.errors.len(),
        }
    }

    pub fn current(&self) -> Option<&Tutorial> {
        self.tutorials.get(self.selected)
    }

    pub fn select(&mut self, index: usize) {
        if !self.tutorials.is_empty() {
            self.selected = index.min(self.tutorials.len() - 1);
        }
    }

    pub fn previous(&mut self, amount: usize) {
        self.selected = self.selected.saturating_sub(amount);
    }

    pub fn next(&mut self, amount: usize) {
        if !self.tutorials.is_empty() {
            self.selected = self
                .selected
                .saturating_add(amount)
                .min(self.tutorials.len() - 1);
        }
    }

    pub fn visible_offset(&self, visible_rows: usize) -> usize {
        if visible_rows == 0 || self.tutorials.len() <= visible_rows {
            return 0;
        }
        self.selected
            .saturating_sub(visible_rows / 2)
            .min(self.tutorials.len() - visible_rows)
    }
}

#[derive(Clone, Debug)]
pub enum TutorialOverlay {
    Menu(TutorialMenu),
    Confirm {
        tutorial: Tutorial,
        resident: usize,
        extended: usize,
    },
}

#[derive(Clone, Copy, Debug, Eq, PartialEq)]
enum TypingPurpose {
    Comment,
    Command,
    ChallengePrompt,
    RetryFeedback { attempts_used: u16 },
    FallbackFeedback,
    FallbackCommand,
    CheckpointPrompt,
    FailureFeedback,
}

#[derive(Clone, Copy, Debug, Eq, PartialEq)]
enum CommentContinuation {
    AdvanceStep,
    WaitForChallenge { attempts_used: u16 },
    TypeFallback,
    WaitForCheckpoint,
    Finish,
}

#[derive(Clone, Debug, Eq, PartialEq)]
enum RunPhase {
    Typing {
        text: String,
        cursor: usize,
        cooldown: u16,
        purpose: TypingPurpose,
        speed: u16,
        typing: TutorialTypingMode,
    },
    WaitingForCommand {
        command: String,
    },
    WaitingForComment {
        text: String,
        continuation: CommentContinuation,
    },
    WaitingForChallenge {
        attempts_used: u16,
    },
    WaitingForCheckpoint,
    Finished,
}

#[derive(Clone, Copy, Debug, Eq, PartialEq)]
pub enum TutorialSubmission {
    Comment,
    Command,
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub enum TutorialAction {
    Insert(String),
    Submit {
        text: String,
        kind: TutorialSubmission,
    },
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub enum ChallengeOutcome {
    Accepted(String),
    Rejected,
}

#[derive(Clone, Debug)]
pub struct TutorialRun {
    tutorial: Tutorial,
    step: usize,
    phase: RunPhase,
    paused: bool,
    database_name: Option<String>,
}

impl TutorialRun {
    pub fn new(tutorial: Tutorial) -> Self {
        let mut run = Self {
            tutorial,
            step: 0,
            phase: RunPhase::Finished,
            paused: false,
            database_name: None,
        };
        run.prepare_step();
        run
    }

    pub fn tutorial(&self) -> &Tutorial {
        &self.tutorial
    }

    pub fn step_number(&self) -> usize {
        (self.step + 1).min(self.tutorial.steps.len())
    }

    pub fn step_count(&self) -> usize {
        self.tutorial.steps.len()
    }

    pub fn is_finished(&self) -> bool {
        matches!(self.phase, RunPhase::Finished)
    }

    pub fn is_typing(&self) -> bool {
        matches!(self.phase, RunPhase::Typing { .. })
    }

    pub fn is_waiting_for_challenge(&self) -> bool {
        matches!(self.phase, RunPhase::WaitingForChallenge { .. })
    }

    pub fn is_waiting_for_checkpoint(&self) -> bool {
        matches!(self.phase, RunPhase::WaitingForCheckpoint)
    }

    pub fn is_waiting_for_command(&self) -> bool {
        matches!(self.phase, RunPhase::WaitingForCommand { .. })
    }

    pub fn paused(&self) -> bool {
        self.paused
    }

    /// Update the small piece of session context that declarative narration
    /// may name. The runner still does not inspect backend result shapes.
    pub fn set_database_name(&mut self, name: Option<&str>) {
        self.database_name = name.map(str::to_owned);
    }

    pub fn toggle_pause(&mut self) {
        if self.is_typing() {
            self.paused = !self.paused;
        }
    }

    pub fn status(&self) -> &'static str {
        if self.paused {
            "paused · Space resume · → finish · Esc stop"
        } else {
            match self.phase {
                RunPhase::Typing { .. } => "typing · Space pause · → finish · Esc stop",
                RunPhase::WaitingForCommand { .. } => "waiting for the real session · Esc stop",
                RunPhase::WaitingForComment { .. } => "committing instruction · Esc stop",
                RunPhase::WaitingForChallenge { .. } => "your turn · Enter submit · Esc stop",
                RunPhase::WaitingForCheckpoint => "checkpoint · Enter continue · Esc stop",
                RunPhase::Finished => "complete",
            }
        }
    }

    pub fn tick(&mut self) -> Option<TutorialAction> {
        if self.paused {
            return None;
        }
        let RunPhase::Typing {
            text,
            cursor,
            cooldown,
            purpose,
            speed,
            typing,
        } = &mut self.phase
        else {
            return None;
        };
        if *cooldown > 0 {
            *cooldown -= 1;
            return None;
        }
        if *typing == TutorialTypingMode::Code {
            let value = text[*cursor..].graphemes(true).take(2).collect::<String>();
            if value.is_empty() {
                return self.finish_typing();
            }
            *cursor += value.len();
            return Some(TutorialAction::Insert(value));
        }
        let Some(grapheme) = text[*cursor..].graphemes(true).next() else {
            return self.finish_typing();
        };
        let value = grapheme.to_owned();
        *cursor += grapheme.len();
        *cooldown = typing_cooldown(
            self.tutorial.typing_wpm,
            self.step,
            text,
            *cursor,
            grapheme,
            *purpose,
            *speed,
        );
        Some(TutorialAction::Insert(value))
    }

    pub fn finish_current_typing(&mut self) -> Option<(String, TutorialAction)> {
        let RunPhase::Typing { text, cursor, .. } = &self.phase else {
            return None;
        };
        let remainder = text[*cursor..].to_owned();
        let action = self.finish_typing()?;
        Some((remainder, action))
    }

    fn finish_typing(&mut self) -> Option<TutorialAction> {
        let RunPhase::Typing { text, purpose, .. } = self.phase.clone() else {
            return None;
        };
        let action = TutorialAction::Submit {
            text: text.clone(),
            kind: if matches!(
                purpose,
                TypingPurpose::Command | TypingPurpose::FallbackCommand
            ) {
                TutorialSubmission::Command
            } else {
                TutorialSubmission::Comment
            },
        };
        match purpose {
            TypingPurpose::Comment => {
                self.wait_for_comment(text.clone(), CommentContinuation::AdvanceStep)
            }
            TypingPurpose::Command | TypingPurpose::FallbackCommand => {
                self.phase = RunPhase::WaitingForCommand { command: text }
            }
            TypingPurpose::ChallengePrompt => self.wait_for_comment(
                text.clone(),
                CommentContinuation::WaitForChallenge { attempts_used: 0 },
            ),
            TypingPurpose::RetryFeedback { attempts_used } => self.wait_for_comment(
                text.clone(),
                CommentContinuation::WaitForChallenge { attempts_used },
            ),
            TypingPurpose::FallbackFeedback => {
                self.wait_for_comment(text.clone(), CommentContinuation::TypeFallback)
            }
            TypingPurpose::CheckpointPrompt => {
                self.wait_for_comment(text.clone(), CommentContinuation::WaitForCheckpoint)
            }
            TypingPurpose::FailureFeedback => {
                self.wait_for_comment(text.clone(), CommentContinuation::Finish)
            }
        }
        Some(action)
    }

    fn wait_for_comment(&mut self, text: String, continuation: CommentContinuation) {
        self.phase = RunPhase::WaitingForComment { text, continuation };
    }

    /// A tutorial never advances past instructional text until the host has
    /// durably appended the exact semicolon comment to its transcript.
    pub fn observe_comment_committed(&mut self, comment: &str) -> bool {
        let RunPhase::WaitingForComment { text, continuation } = self.phase.clone() else {
            return false;
        };
        if text != comment {
            return false;
        }
        match continuation {
            CommentContinuation::AdvanceStep => self.advance_step(),
            CommentContinuation::WaitForChallenge { attempts_used } => {
                self.phase = RunPhase::WaitingForChallenge { attempts_used };
            }
            CommentContinuation::TypeFallback => {
                let fallback = self
                    .challenge()
                    .map(|(_, _, fallback, _, _)| fallback.trim().to_owned());
                if let Some(fallback) = fallback {
                    self.begin_typing(
                        fallback,
                        TypingPurpose::FallbackCommand,
                        100,
                        TutorialTypingMode::Natural,
                    );
                } else {
                    self.phase = RunPhase::Finished;
                }
            }
            CommentContinuation::WaitForCheckpoint => {
                self.phase = RunPhase::WaitingForCheckpoint;
            }
            CommentContinuation::Finish => self.phase = RunPhase::Finished,
        }
        true
    }

    pub fn submit_challenge(&mut self, source: &str) -> ChallengeOutcome {
        let RunPhase::WaitingForChallenge { attempts_used } = self.phase else {
            return ChallengeOutcome::Rejected;
        };
        let Some((answers, attempts, _fallback, _prompt, answer_match)) = self.challenge() else {
            return ChallengeOutcome::Rejected;
        };
        let source = source.trim();
        if answers
            .iter()
            .any(|answer| challenge_answer_matches(answer_match, answer, source))
        {
            let command = source.to_owned();
            self.phase = RunPhase::WaitingForCommand {
                command: command.clone(),
            };
            return ChallengeOutcome::Accepted(command);
        }

        let attempts_used = attempts_used.saturating_add(1);
        if attempts_used < attempts {
            self.begin_typing(
                "; That is not one of the forms this tutorial recognizes. Try once more:"
                    .to_owned(),
                TypingPurpose::RetryFeedback { attempts_used },
                100,
                TutorialTypingMode::Natural,
            );
        } else {
            self.begin_typing(
                "; Let's use the tutorial's expected form and keep going:".to_owned(),
                TypingPurpose::FallbackFeedback,
                100,
                TutorialTypingMode::Natural,
            );
        }
        ChallengeOutcome::Rejected
    }

    pub fn continue_checkpoint(&mut self) -> bool {
        if !self.is_waiting_for_checkpoint() {
            return false;
        }
        self.advance_step();
        true
    }

    pub fn observe_command_result(&mut self, command: &str, ok: bool) -> bool {
        let RunPhase::WaitingForCommand { command: expected } = &self.phase else {
            return false;
        };
        if expected != command {
            return false;
        }
        if ok {
            self.advance_step();
        } else {
            self.begin_typing(
                "; The command failed, so the tutorial is stopping here. The session is yours to inspect."
                    .to_owned(),
                TypingPurpose::FailureFeedback,
                100,
                TutorialTypingMode::Natural,
            );
        }
        true
    }

    fn challenge(&self) -> Option<(&[String], u16, &str, &str, ChallengeMatch)> {
        match self.tutorial.steps.get(self.step)? {
            TutorialStep::Challenge {
                prompt,
                answers,
                fallback,
                attempts,
                answer_match,
                ..
            } => Some((answers, *attempts, fallback, prompt, *answer_match)),
            _ => None,
        }
    }

    fn advance_step(&mut self) {
        self.step = self.step.saturating_add(1);
        self.paused = false;
        self.prepare_step();
    }

    fn prepare_step(&mut self) {
        let Some(step) = self.tutorial.steps.get(self.step).cloned() else {
            self.phase = RunPhase::Finished;
            return;
        };
        match step {
            TutorialStep::Comment { text, speed } => {
                let text = self.render_text(&text);
                self.begin_typing(
                    comment_text(&text),
                    TypingPurpose::Comment,
                    speed,
                    TutorialTypingMode::Natural,
                )
            }
            TutorialStep::Command {
                text,
                speed,
                typing,
            } => {
                let text = self.render_text(&text);
                self.begin_typing(
                    text.trim().to_owned(),
                    TypingPurpose::Command,
                    speed,
                    typing,
                )
            }
            TutorialStep::Challenge { prompt, speed, .. } => {
                let prompt = self.render_text(&prompt);
                self.begin_typing(
                    prompt_comment_text(&prompt),
                    TypingPurpose::ChallengePrompt,
                    speed,
                    TutorialTypingMode::Natural,
                )
            }
            TutorialStep::Checkpoint { text, speed } => {
                let text = self.render_text(&text);
                self.begin_typing(
                    prompt_comment_text(&text),
                    TypingPurpose::CheckpointPrompt,
                    speed,
                    TutorialTypingMode::Natural,
                )
            }
        }
    }

    fn render_text(&self, text: &str) -> String {
        text.replace(
            "{{database}}",
            self.database_name
                .as_deref()
                .unwrap_or("the current database"),
        )
    }

    fn begin_typing(
        &mut self,
        text: String,
        purpose: TypingPurpose,
        speed: u16,
        typing: TutorialTypingMode,
    ) {
        self.phase = RunPhase::Typing {
            text,
            cursor: 0,
            cooldown: 0,
            purpose,
            speed,
            typing,
        };
        self.paused = false;
    }
}

fn comment_text(text: &str) -> String {
    format!("; {}", text.trim())
}

fn prompt_comment_text(text: &str) -> String {
    let text = text
        .trim()
        .trim_end_matches(|character| matches!(character, ':' | '.' | '?' | '!'));
    format!("; {text}:")
}

#[derive(Clone, Debug, Eq, PartialEq)]
enum SlogToken {
    Open,
    Close,
    Atom(String),
    Quoted(String),
}

#[derive(Clone, Debug)]
struct ParsedRule {
    head: Vec<SlogToken>,
    body: Vec<Vec<SlogToken>>,
}

#[derive(Clone, Debug, Eq, PartialEq)]
enum CanonicalToken {
    Open,
    Close,
    Literal(String),
    Variable(usize),
    Wildcard,
}

fn challenge_answer_matches(mode: ChallengeMatch, expected: &str, source: &str) -> bool {
    match mode {
        ChallengeMatch::Exact => {
            expected.trim() == source.trim()
                || matches!(
                    (tokenize_slog(expected), tokenize_slog(source)),
                    (Some(expected), Some(source)) if expected == source
                )
        }
        ChallengeMatch::SlogRule => slog_rules_equivalent(expected, source),
    }
}

fn tokenize_slog(source: &str) -> Option<Vec<SlogToken>> {
    let mut tokens = Vec::new();
    let mut chars = source.chars().peekable();
    while let Some(character) = chars.next() {
        match character {
            character if character.is_whitespace() => {}
            '(' => tokens.push(SlogToken::Open),
            ')' => tokens.push(SlogToken::Close),
            '"' => {
                let mut quoted = String::from('"');
                let mut escaped = false;
                let mut closed = false;
                for character in chars.by_ref() {
                    quoted.push(character);
                    if escaped {
                        escaped = false;
                    } else if character == '\\' {
                        escaped = true;
                    } else if character == '"' {
                        closed = true;
                        break;
                    }
                }
                if !closed {
                    return None;
                }
                tokens.push(SlogToken::Quoted(quoted));
            }
            first => {
                let mut atom = String::from(first);
                while let Some(next) = chars.peek().copied() {
                    if next.is_whitespace() || matches!(next, '(' | ')' | '"') {
                        break;
                    }
                    atom.push(next);
                    chars.next();
                }
                tokens.push(SlogToken::Atom(atom));
            }
        }
    }
    Some(tokens)
}

fn parse_slog_rule(source: &str) -> Option<ParsedRule> {
    let source = source.trim();
    let rest = source.strip_prefix("rule")?;
    if !rest.starts_with(char::is_whitespace) {
        return None;
    }
    let tokens = tokenize_slog(rest)?;
    let mut depth = 0_i32;
    let mut arrow = None;
    for (index, token) in tokens.iter().enumerate() {
        match token {
            SlogToken::Open => depth += 1,
            SlogToken::Close => {
                depth -= 1;
                if depth < 0 {
                    return None;
                }
            }
            SlogToken::Atom(value) if depth == 0 && matches!(value.as_str(), "<--" | "-->") => {
                if arrow.replace((index, value.as_str())).is_some() {
                    return None;
                }
            }
            _ => {}
        }
    }
    if depth != 0 {
        return None;
    }
    let (arrow_index, direction) = arrow?;
    let left = split_rule_clauses(&tokens[..arrow_index])?;
    let right = split_rule_clauses(&tokens[arrow_index + 1..])?;
    let (head, body) = if direction == "<--" {
        if left.len() != 1 || right.is_empty() {
            return None;
        }
        (left.into_iter().next()?, right)
    } else {
        if right.len() != 1 || left.is_empty() {
            return None;
        }
        (right.into_iter().next()?, left)
    };
    (body.len() <= 6).then_some(ParsedRule { head, body })
}

fn split_rule_clauses(tokens: &[SlogToken]) -> Option<Vec<Vec<SlogToken>>> {
    let mut clauses = Vec::new();
    let mut start = 0;
    while start < tokens.len() {
        if tokens[start] != SlogToken::Open {
            return None;
        }
        let mut depth = 0_i32;
        let mut end = None;
        for (offset, token) in tokens[start..].iter().enumerate() {
            match token {
                SlogToken::Open => depth += 1,
                SlogToken::Close => {
                    depth -= 1;
                    if depth == 0 {
                        end = Some(start + offset + 1);
                        break;
                    }
                    if depth < 0 {
                        return None;
                    }
                }
                _ => {}
            }
        }
        let end = end?;
        clauses.push(tokens[start..end].to_vec());
        start = end;
    }
    Some(clauses)
}

fn slog_rules_equivalent(expected: &str, source: &str) -> bool {
    let (Some(expected), Some(source)) = (parse_slog_rule(expected), parse_slog_rule(source))
    else {
        return false;
    };
    let expected = canonical_rule_variants(&expected);
    canonical_rule_variants(&source)
        .iter()
        .any(|candidate| expected.contains(candidate))
}

fn canonical_rule_variants(
    rule: &ParsedRule,
) -> Vec<(Vec<CanonicalToken>, Vec<Vec<CanonicalToken>>)> {
    permutations(rule.body.len())
        .into_iter()
        .map(|order| {
            let mut variables = BTreeMap::new();
            let head = canonicalize_clause(&rule.head, &mut variables);
            let body = order
                .into_iter()
                .map(|index| canonicalize_clause(&rule.body[index], &mut variables))
                .collect();
            (head, body)
        })
        .collect()
}

fn canonicalize_clause(
    clause: &[SlogToken],
    variables: &mut BTreeMap<String, usize>,
) -> Vec<CanonicalToken> {
    clause
        .iter()
        .map(|token| match token {
            SlogToken::Open => CanonicalToken::Open,
            SlogToken::Close => CanonicalToken::Close,
            SlogToken::Quoted(value) => CanonicalToken::Literal(value.clone()),
            SlogToken::Atom(value) if value == "_" => CanonicalToken::Wildcard,
            SlogToken::Atom(value)
                if value
                    .chars()
                    .next()
                    .is_some_and(|first| first.is_ascii_uppercase()) =>
            {
                let next = variables.len();
                CanonicalToken::Variable(*variables.entry(value.clone()).or_insert(next))
            }
            SlogToken::Atom(value) => CanonicalToken::Literal(value.clone()),
        })
        .collect()
}

fn permutations(length: usize) -> Vec<Vec<usize>> {
    fn extend(prefix: &mut Vec<usize>, used: &mut [bool], output: &mut Vec<Vec<usize>>) {
        if prefix.len() == used.len() {
            output.push(prefix.clone());
            return;
        }
        for index in 0..used.len() {
            if used[index] {
                continue;
            }
            used[index] = true;
            prefix.push(index);
            extend(prefix, used, output);
            prefix.pop();
            used[index] = false;
        }
    }

    let mut output = Vec::new();
    extend(&mut Vec::new(), &mut vec![false; length], &mut output);
    output
}

fn validate_command(text: &str) -> Result<(), String> {
    let text = text.trim();
    if text.is_empty() {
        return Err("command must not be empty".to_owned());
    }
    if text.starts_with(';') {
        return Err("use a comment step for narration".to_owned());
    }
    if matches!(
        text,
        ":clear" | ":quit" | "quit" | "exit" | ":tutorials" | ":tutorial stop" | "discard session"
    ) {
        return Err(
            "tutorial lifecycle and transcript commands cannot be tutorial steps".to_owned(),
        );
    }
    Ok(())
}

fn typing_cooldown(
    [minimum, maximum]: [u16; 2],
    step: usize,
    text: &str,
    cursor: usize,
    grapheme: &str,
    purpose: TypingPurpose,
    speed: u16,
) -> u16 {
    let spread = u32::from(maximum - minimum) + 1;
    let hash = (step as u32)
        .wrapping_mul(1_103_515_245)
        .wrapping_add(cursor as u32 * 12_345)
        .wrapping_add(typing_purpose_code(purpose) * 97);
    let wpm = u32::from(minimum) + hash % spread;
    let mut milliseconds = 12_000 / wpm.max(1);
    if matches!(grapheme, "." | "," | ":" | ";" | "\n") {
        milliseconds = milliseconds.saturating_add(80);
    }
    if grapheme.chars().all(char::is_whitespace)
        && text[cursor..]
            .chars()
            .next()
            .is_some_and(|character| !character.is_whitespace())
    {
        let next_word = text[..cursor].split_whitespace().count().saturating_add(1);
        if pause_before_word(step, purpose, next_word) {
            milliseconds = milliseconds.saturating_add(440 + hash % 241);
        }
    }
    milliseconds = milliseconds.saturating_mul(100) / u32::from(speed).max(1);
    (milliseconds.div_ceil(TUTORIAL_TICK_MS as u32) as u16).saturating_sub(1)
}

fn pause_before_word(step: usize, purpose: TypingPurpose, word: usize) -> bool {
    let seed = (step as u32)
        .wrapping_mul(2_654_435_761)
        .wrapping_add(typing_purpose_code(purpose) * 131);
    let mut boundary = 7 + (seed % 6) as usize;
    let mut group = 1_u32;
    while boundary < word {
        let interval = 7 + (seed.wrapping_add(group * 97) % 6) as usize;
        boundary = boundary.saturating_add(interval);
        group = group.saturating_add(1);
    }
    boundary == word
}

fn typing_purpose_code(purpose: TypingPurpose) -> u32 {
    match purpose {
        TypingPurpose::Comment => 0,
        TypingPurpose::Command => 1,
        TypingPurpose::ChallengePrompt => 2,
        TypingPurpose::RetryFeedback { .. } => 3,
        TypingPurpose::FallbackFeedback => 4,
        TypingPurpose::FallbackCommand => 5,
        TypingPurpose::CheckpointPrompt => 6,
        TypingPurpose::FailureFeedback => 7,
    }
}

#[cfg(test)]
mod tests {
    use super::{
        ChallengeMatch, ChallengeOutcome, Tutorial, TutorialAction, TutorialRun,
        TutorialSubmission, TypingPurpose, challenge_answer_matches, slog_rules_equivalent,
        typing_cooldown,
    };

    const SOURCE: &str = r#"
format = 1
id = "query-basics"
title = "Query basics"
summary = "Learn one observation."
session = "fresh"
typing_wpm = [110, 160]
effects = ["discard-session"]

[[steps]]
type = "comment"
text = "Let us inspect the server."

[[steps]]
type = "command"
text = ":status"

[[steps]]
type = "challenge"
prompt = "Ping it."
answers = [":ping", "ping"]
fallback = ":ping"
attempts = 1

[[steps]]
type = "checkpoint"
text = "Press Enter to finish."
"#;

    fn finish_typing(run: &mut TutorialRun) -> TutorialAction {
        let action = run.finish_current_typing().expect("typing").1;
        if let TutorialAction::Submit {
            text,
            kind: TutorialSubmission::Comment,
        } = &action
        {
            assert!(run.observe_comment_committed(text));
        }
        action
    }

    #[test]
    fn parses_and_validates_the_versioned_toml_contract() {
        let tutorial = Tutorial::parse(SOURCE).expect("valid tutorial");
        assert_eq!(tutorial.id, "query-basics");
        assert_eq!(tutorial.steps.len(), 4);
        assert!(Tutorial::parse(&SOURCE.replace("format = 1", "format = 9")).is_err());
        assert!(
            Tutorial::parse(&SOURCE.replace("fallback = \":ping\"", "fallback = \"wat\"")).is_err()
        );
        assert!(
            Tutorial::parse(&SOURCE.replace(
                "text = \"Let us inspect the server.\"",
                "text = \"Let us inspect the server.\"\nspeed = 0"
            ))
            .is_err()
        );
        assert!(Tutorial::parse(&SOURCE.replace(":status", ":clear")).is_err());
        for source in [
            include_str!("../tutorials/01-repl-basics.toml"),
            include_str!("../tutorials/02-structs-and-demands.toml"),
            include_str!("../tutorials/03-collection-toolbox.toml"),
            include_str!("../tutorials/04-lambda-kcfa.toml"),
        ] {
            Tutorial::parse(source).expect("the shipped tutorial follows the public format");
        }
    }

    #[test]
    fn instructional_text_cannot_advance_until_its_comment_is_committed() {
        let mut run = TutorialRun::new(Tutorial::parse(SOURCE).expect("tutorial"));
        let action = run.finish_current_typing().expect("typing").1;
        assert_eq!(
            action,
            TutorialAction::Submit {
                text: "; Let us inspect the server.".to_owned(),
                kind: TutorialSubmission::Comment,
            }
        );
        assert!(run.finish_current_typing().is_none());
        assert!(!run.observe_comment_committed("; a different comment"));
        assert!(run.observe_comment_committed("; Let us inspect the server."));
        assert!(run.is_typing(), "the command step begins only after commit");
    }

    #[test]
    fn runner_waits_for_real_command_results_and_checkpoints() {
        let mut run = TutorialRun::new(Tutorial::parse(SOURCE).expect("tutorial"));
        assert_eq!(
            finish_typing(&mut run),
            TutorialAction::Submit {
                text: "; Let us inspect the server.".to_owned(),
                kind: TutorialSubmission::Comment,
            }
        );
        assert_eq!(
            finish_typing(&mut run),
            TutorialAction::Submit {
                text: ":status".to_owned(),
                kind: TutorialSubmission::Command,
            }
        );
        assert!(run.is_waiting_for_command());
        assert!(!run.observe_command_result(":ping", true));
        assert!(run.observe_command_result(":status", true));
        assert_eq!(
            finish_typing(&mut run),
            TutorialAction::Submit {
                text: "; Ping it:".to_owned(),
                kind: TutorialSubmission::Comment,
            }
        );
        assert!(run.is_waiting_for_challenge());
        assert_eq!(
            run.submit_challenge(" ping "),
            ChallengeOutcome::Accepted("ping".to_owned())
        );
        assert!(run.observe_command_result("ping", true));
        let _ = finish_typing(&mut run);
        assert!(run.is_waiting_for_checkpoint());
        assert!(run.continue_checkpoint());
        assert!(run.is_finished());
    }

    #[test]
    fn unrecognized_answers_are_not_executed_and_fall_back_visibly() {
        let mut run = TutorialRun::new(Tutorial::parse(SOURCE).expect("tutorial"));
        let _ = finish_typing(&mut run);
        let _ = finish_typing(&mut run);
        assert!(run.observe_command_result(":status", true));
        let _ = finish_typing(&mut run);
        assert_eq!(
            run.submit_challenge("drop everything"),
            ChallengeOutcome::Rejected
        );
        assert!(run.is_typing());
        let feedback = finish_typing(&mut run);
        assert!(matches!(
            feedback,
            TutorialAction::Submit {
                kind: TutorialSubmission::Comment,
                ..
            }
        ));
        let fallback = finish_typing(&mut run);
        assert_eq!(
            fallback,
            TutorialAction::Submit {
                text: ":ping".to_owned(),
                kind: TutorialSubmission::Command,
            }
        );
    }

    #[test]
    fn cadence_uses_sparser_word_pauses_and_honors_step_speed() {
        let text = (1..=40)
            .map(|word| format!("word{word}"))
            .collect::<Vec<_>>()
            .join(" ");
        let pauses = text
            .char_indices()
            .filter(|(_, character)| *character == ' ')
            .filter_map(|(index, _)| {
                let cursor = index + 1;
                let cooldown = typing_cooldown(
                    [180, 210],
                    3,
                    &text,
                    cursor,
                    " ",
                    TypingPurpose::Comment,
                    100,
                );
                (cooldown >= 12).then(|| text[..cursor].split_whitespace().count() + 1)
            })
            .collect::<Vec<_>>();
        assert!(pauses.len() >= 3);
        assert!(pauses[0] >= 7 && pauses[0] <= 12);
        assert!(
            pauses
                .windows(2)
                .all(|pair| (7..=12).contains(&(pair[1] - pair[0])))
        );

        let normal = typing_cooldown([40, 40], 0, "x", 1, "x", TypingPurpose::Command, 100);
        let fast = typing_cooldown([40, 40], 0, "x", 1, "x", TypingPurpose::Command, 140);
        assert!(fast < normal);
    }

    #[test]
    fn exact_challenges_ignore_only_irrelevant_slog_spacing() {
        assert!(challenge_answer_matches(
            ChallengeMatch::Exact,
            "?(path 1 5)",
            "? ( path 1 5 )"
        ));
        assert!(!challenge_answer_matches(
            ChallengeMatch::Exact,
            "?(path 1 5)",
            "?(path 1 4)"
        ));
    }

    #[test]
    fn rule_challenges_accept_alpha_renaming_clause_order_and_arrow_direction() {
        let expected = "rule (path X Z) <-- (path X Y) (edge Y Z)";
        assert!(slog_rules_equivalent(
            expected,
            "rule (edge Middle End) (path Start Middle) --> (path Start End)"
        ));
        assert!(slog_rules_equivalent(
            expected,
            "rule (path From To) <-- (edge Via To) (path From Via)"
        ));
        assert!(!slog_rules_equivalent(
            expected,
            "rule (path From To) <-- (path From From) (edge From To)"
        ));
        assert!(!slog_rules_equivalent(
            expected,
            "rule (path From To) <-- (path From Via) (edge Via 7)"
        ));
    }

    #[test]
    fn code_typing_batches_graphemes_without_natural_cooldowns() {
        let tutorial = Tutorial::parse(
            r#"
format = 1
id = "fast-code"
title = "Fast code"
summary = "Exercise code typing."
typing_wpm = [20, 20]

[[steps]]
type = "command"
text = "ab\ncd"
typing = "code"
"#,
        )
        .expect("tutorial");
        let mut run = TutorialRun::new(tutorial);
        assert_eq!(run.tick(), Some(TutorialAction::Insert("ab".to_owned())));
        assert_eq!(run.tick(), Some(TutorialAction::Insert("\nc".to_owned())));
        assert_eq!(run.tick(), Some(TutorialAction::Insert("d".to_owned())));
        assert!(matches!(
            run.tick(),
            Some(TutorialAction::Submit {
                kind: TutorialSubmission::Command,
                ..
            })
        ));
    }

    #[test]
    fn every_shipped_instruction_becomes_a_durable_comment_before_advancing() {
        for source in [
            include_str!("../tutorials/01-repl-basics.toml"),
            include_str!("../tutorials/02-structs-and-demands.toml"),
            include_str!("../tutorials/03-collection-toolbox.toml"),
            include_str!("../tutorials/04-lambda-kcfa.toml"),
        ] {
            let tutorial = Tutorial::parse(source).expect("shipped tutorial");
            let expected_comments = tutorial
                .steps
                .iter()
                .filter(|step| !matches!(step, super::TutorialStep::Command { .. }))
                .count();
            let mut run = TutorialRun::new(tutorial);
            let mut committed = Vec::new();
            for _ in 0..200 {
                if run.is_finished() {
                    break;
                }
                if run.is_typing() {
                    let action = run.finish_current_typing().expect("typing action").1;
                    match action {
                        TutorialAction::Submit {
                            text,
                            kind: TutorialSubmission::Comment,
                        } => {
                            committed.push(text.clone());
                            assert!(run.observe_comment_committed(&text));
                        }
                        TutorialAction::Submit {
                            text,
                            kind: TutorialSubmission::Command,
                        } => assert!(run.observe_command_result(&text, true)),
                        TutorialAction::Insert(_) => unreachable!("finish returns a submission"),
                    }
                } else if run.is_waiting_for_challenge() {
                    let fallback = run.challenge().expect("challenge").2.to_owned();
                    assert_eq!(
                        run.submit_challenge(&fallback),
                        ChallengeOutcome::Accepted(fallback.clone())
                    );
                    assert!(run.observe_command_result(&fallback, true));
                } else if run.is_waiting_for_checkpoint() {
                    assert!(run.continue_checkpoint());
                } else {
                    panic!("runner stalled before an instruction was committed");
                }
            }
            assert!(run.is_finished());
            assert_eq!(committed.len(), expected_comments);
            assert!(committed.iter().all(|comment| comment.starts_with("; ")));
        }
    }
}
