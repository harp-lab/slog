use ratatui::style::Color;

/// One coherent terminal palette. The REPL never paints a full-screen
/// background: the terminal's own background shows through, so each palette
/// only chooses foreground/selection colors that read on that background.
/// `dark()` is the original palette; `light()` targets light terminals.
#[derive(Clone, Copy, Debug, Eq, PartialEq)]
pub struct Theme {
    pub name: &'static str,
    /// Primary content: editor text, titles, selected values.
    pub text: Color,
    /// Regular result body lines.
    pub body: Color,
    /// De-emphasized lines: comments, generated commands, presence notes.
    pub faint: Color,
    /// Secondary annotations: actors, details, footers.
    pub muted: Color,
    /// Commands, links, and key hints.
    pub accent: Color,
    /// Search matches, table headers, and attention prompts.
    pub highlight: Color,
    /// Successful results and resident-session markers.
    pub success: Color,
    /// Errors and stale warnings.
    pub error: Color,
    /// The blinking tutorial input hint.
    pub hint: Color,
    /// Panel borders.
    pub panel: Color,
    /// Background of the selected live-canvas line and completion candidate.
    pub selection_bg: Color,
    /// Foreground over an `accent` background (menu selection rows).
    pub on_accent: Color,
    logo_base: (u8, u8, u8),
    logo_step: (u8, u8, u8),
}

impl Theme {
    pub const fn dark() -> Self {
        Self {
            name: "dark",
            text: Color::White,
            body: Color::Gray,
            faint: Color::DarkGray,
            muted: Color::Rgb(124, 139, 161),
            accent: Color::Rgb(62, 207, 227),
            highlight: Color::Rgb(244, 114, 182),
            success: Color::Rgb(74, 222, 128),
            error: Color::LightRed,
            hint: Color::LightBlue,
            panel: Color::Rgb(30, 36, 50),
            selection_bg: Color::Rgb(30, 36, 50),
            on_accent: Color::Black,
            logo_base: (45, 180, 230),
            logo_step: (16, 8, 0),
        }
    }

    pub const fn light() -> Self {
        Self {
            name: "light",
            text: Color::Rgb(23, 32, 48),
            body: Color::Rgb(52, 64, 84),
            faint: Color::Rgb(148, 158, 174),
            muted: Color::Rgb(101, 113, 133),
            accent: Color::Rgb(11, 116, 144),
            highlight: Color::Rgb(190, 24, 93),
            success: Color::Rgb(21, 122, 65),
            error: Color::Rgb(185, 28, 28),
            hint: Color::Rgb(29, 78, 216),
            panel: Color::Rgb(195, 205, 219),
            selection_bg: Color::Rgb(222, 230, 240),
            on_accent: Color::Rgb(250, 252, 255),
            logo_base: (10, 82, 150),
            logo_step: (6, 12, 10),
        }
    }

    pub fn named(name: &str) -> Option<Self> {
        match name {
            "dark" => Some(Self::dark()),
            "light" => Some(Self::light()),
            _ => None,
        }
    }

    /// One splash-logo line color; `index` counts the logo's rows from the top.
    pub fn logo(&self, index: usize) -> Color {
        let step = |base: u8, step: u8| base.saturating_add(step.saturating_mul(index as u8));
        Color::Rgb(
            step(self.logo_base.0, self.logo_step.0),
            step(self.logo_base.1, self.logo_step.1),
            step(self.logo_base.2, self.logo_step.2),
        )
    }
}

/// Best-effort detection of the terminal's background, for choosing the
/// startup palette when neither `--light` nor `--dark` was given. Returns
/// `None` when the background cannot be established; the caller then keeps
/// the dark default.
///
/// The primary probe writes the standard OSC 11 color query to `/dev/tty`
/// and reads the reply there, so the workbench's stdin/stdout streams are
/// never touched. A terminal that does not answer costs the full timeout,
/// which the caller overlaps with the much slower Racket backend launch.
/// When OSC 11 yields nothing, the `COLORFGBG` convention (rxvt, konsole)
/// is consulted before giving up.
pub fn detect() -> Option<Theme> {
    let light = osc11_background_is_light(std::time::Duration::from_millis(400))
        .or_else(|| colorfgbg_is_light(&std::env::var("COLORFGBG").ok()?))?;
    Some(if light { Theme::light() } else { Theme::dark() })
}

#[cfg(unix)]
fn osc11_background_is_light(timeout: std::time::Duration) -> Option<bool> {
    use std::io::{Read, Write};
    use std::time::Instant;

    let mut tty = std::fs::OpenOptions::new()
        .read(true)
        .write(true)
        .open("/dev/tty")
        .ok()?;
    // Raw mode keeps the reply out of the line editor and off the screen;
    // the guard restores the previous settings even on an early return.
    struct RestoreTermios<'fd> {
        tty: &'fd std::fs::File,
        saved: rustix::termios::Termios,
    }
    impl Drop for RestoreTermios<'_> {
        fn drop(&mut self) {
            let _ = rustix::termios::tcsetattr(
                self.tty,
                rustix::termios::OptionalActions::Now,
                &self.saved,
            );
        }
    }
    let saved = rustix::termios::tcgetattr(&tty).ok()?;
    let mut raw = saved.clone();
    raw.make_raw();
    rustix::termios::tcsetattr(&tty, rustix::termios::OptionalActions::Now, &raw).ok()?;
    let handle = tty.try_clone().ok()?;
    let _restore = RestoreTermios {
        tty: &handle,
        saved,
    };

    tty.write_all(b"\x1b]11;?\x07").ok()?;
    tty.flush().ok()?;

    let deadline = Instant::now() + timeout;
    let mut reply = Vec::new();
    loop {
        let remaining = deadline.checked_duration_since(Instant::now())?;
        let timeout = rustix::event::Timespec {
            tv_sec: remaining.as_secs() as _,
            tv_nsec: remaining.subsec_nanos() as _,
        };
        let mut fds = [rustix::event::PollFd::new(
            &tty,
            rustix::event::PollFlags::IN,
        )];
        if rustix::event::poll(&mut fds, Some(&timeout)).ok()? == 0 {
            return None;
        }
        let mut byte = [0u8];
        if tty.read(&mut byte).ok()? != 1 {
            return None;
        }
        reply.push(byte[0]);
        // Replies end with BEL or the two-byte ST terminator.
        if byte[0] == 0x07 || reply.ends_with(b"\x1b\\") {
            return osc11_reply_is_light(&reply);
        }
        if reply.len() > 256 {
            return None;
        }
    }
}

#[cfg(not(unix))]
fn osc11_background_is_light(_timeout: std::time::Duration) -> Option<bool> {
    None
}

/// Parses a terminal's OSC 11 reply, e.g. `ESC]11;rgb:1e1e/2424/3232 BEL`.
fn osc11_reply_is_light(reply: &[u8]) -> Option<bool> {
    let text = str::from_utf8(reply).ok()?;
    let spec = &text[text.find("]11;")? + 4..];
    let end = spec.find(['\u{7}', '\u{1b}']).unwrap_or(spec.len());
    color_spec_is_light(spec[..end].trim())
}

/// Classifies an X11-style color specification: `rgb:R/G/B` (1-4 hex digits
/// per component), `rgba:R/G/B/A`, or `#RGB`/`#RRGGBB`-style hex.
fn color_spec_is_light(spec: &str) -> Option<bool> {
    let component = |digits: &str| -> Option<f64> {
        if digits.is_empty() || digits.len() > 4 {
            return None;
        }
        let value = u32::from_str_radix(digits, 16).ok()?;
        let max = 16u32.pow(digits.len() as u32) - 1;
        Some(f64::from(value) / f64::from(max))
    };
    let (red, green, blue) = if let Some(body) = spec
        .strip_prefix("rgb:")
        .or_else(|| spec.strip_prefix("rgba:"))
    {
        let mut parts = body.split('/');
        let (red, green, blue) = (parts.next()?, parts.next()?, parts.next()?);
        (component(red)?, component(green)?, component(blue)?)
    } else if let Some(body) = spec.strip_prefix('#') {
        let width = body.len() / 3;
        if width == 0 || width > 4 || body.len() != width * 3 {
            return None;
        }
        (
            component(&body[..width])?,
            component(&body[width..2 * width])?,
            component(&body[2 * width..])?,
        )
    } else {
        return None;
    };
    Some(0.2126 * red + 0.7152 * green + 0.0722 * blue > 0.5)
}

/// Interprets the `COLORFGBG` convention: semicolon-separated fields whose
/// last entry is the background's ANSI color number.
fn colorfgbg_is_light(value: &str) -> Option<bool> {
    let background: u8 = value.split(';').next_back()?.trim().parse().ok()?;
    Some(!(background <= 6 || background == 8))
}

#[cfg(test)]
mod tests {
    use super::{Theme, color_spec_is_light, colorfgbg_is_light, osc11_reply_is_light};
    use ratatui::style::Color;

    #[test]
    fn named_palettes_resolve_and_reject_unknown_names() {
        assert_eq!(Theme::named("dark"), Some(Theme::dark()));
        assert_eq!(Theme::named("light"), Some(Theme::light()));
        assert_eq!(Theme::named("solarized"), None);
        assert_eq!(Theme::named(""), None);
    }

    #[test]
    fn osc11_replies_classify_light_and_dark_backgrounds() {
        assert_eq!(
            osc11_reply_is_light(b"\x1b]11;rgb:ffff/ffff/ffff\x07"),
            Some(true)
        );
        assert_eq!(
            osc11_reply_is_light(b"\x1b]11;rgb:1e1e/2424/3232\x1b\\"),
            Some(false)
        );
        assert_eq!(
            osc11_reply_is_light(b"\x1b]11;rgb:fd/f6/e3\x07"),
            Some(true)
        );
        assert_eq!(osc11_reply_is_light(b"\x1b]11;#002b36\x07"), Some(false));
        assert_eq!(osc11_reply_is_light(b"\x1b]11;?\x07"), None);
        assert_eq!(osc11_reply_is_light(b"garbage"), None);
        assert_eq!(
            osc11_reply_is_light(b"\x1b]10;rgb:ffff/ffff/ffff\x07"),
            None
        );
    }

    #[test]
    fn color_specs_cover_every_component_width_and_reject_malformed_input() {
        assert_eq!(color_spec_is_light("rgb:f/f/f"), Some(true));
        assert_eq!(color_spec_is_light("rgb:00/00/00"), Some(false));
        assert_eq!(color_spec_is_light("rgba:ffff/ffff/ffff/0000"), Some(true));
        assert_eq!(color_spec_is_light("#fff"), Some(true));
        assert_eq!(color_spec_is_light("#000000"), Some(false));
        // Green dominates perceived luminance; pure blue stays dark.
        assert_eq!(color_spec_is_light("rgb:0000/ffff/0000"), Some(true));
        assert_eq!(color_spec_is_light("rgb:0000/0000/ffff"), Some(false));
        assert_eq!(color_spec_is_light("rgb:ffff/ffff"), None);
        assert_eq!(color_spec_is_light("rgb:fffff/ffff/ffff"), None);
        assert_eq!(color_spec_is_light("#ffff"), None);
        assert_eq!(color_spec_is_light("teal"), None);
    }

    #[test]
    fn colorfgbg_uses_the_final_background_field() {
        assert_eq!(colorfgbg_is_light("0;15"), Some(true));
        assert_eq!(colorfgbg_is_light("15;0"), Some(false));
        assert_eq!(colorfgbg_is_light("15;default;0"), Some(false));
        assert_eq!(colorfgbg_is_light("12;8"), Some(false));
        assert_eq!(colorfgbg_is_light("0;7"), Some(true));
        assert_eq!(colorfgbg_is_light("default;default"), None);
        assert_eq!(colorfgbg_is_light(""), None);
    }

    #[test]
    fn dark_logo_gradient_matches_the_original_splash_formula() {
        for index in 0..6 {
            assert_eq!(
                Theme::dark().logo(index),
                Color::Rgb(45 + index as u8 * 16, 180 + index as u8 * 8, 230)
            );
        }
    }
}
