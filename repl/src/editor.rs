use unicode_segmentation::UnicodeSegmentation;
use unicode_width::UnicodeWidthStr;

#[derive(Debug, Default)]
pub struct Editor {
    text: String,
    cursor: usize,
}

impl Editor {
    pub fn text(&self) -> &str {
        &self.text
    }

    pub fn is_empty(&self) -> bool {
        self.text.is_empty()
    }

    pub fn cursor(&self) -> usize {
        self.cursor
    }

    pub fn insert(&mut self, value: &str) {
        self.text.insert_str(self.cursor, value);
        self.cursor += value.len();
    }

    pub fn replace(&mut self, value: String) {
        self.cursor = value.len();
        self.text = value;
    }

    pub fn replace_range(&mut self, start: usize, end: usize, value: &str) {
        assert!(start <= end);
        assert!(self.text.is_char_boundary(start));
        assert!(self.text.is_char_boundary(end));
        self.text.replace_range(start..end, value);
        self.cursor = start + value.len();
    }

    pub fn clear(&mut self) {
        self.text.clear();
        self.cursor = 0;
    }

    pub fn take(&mut self) -> String {
        self.cursor = 0;
        std::mem::take(&mut self.text)
    }

    pub fn move_left(&mut self) {
        self.cursor = self.previous_grapheme();
    }

    pub fn move_right(&mut self) {
        if let Some(grapheme) = self.text[self.cursor..].graphemes(true).next() {
            self.cursor += grapheme.len();
        }
    }

    pub fn move_home(&mut self) {
        self.cursor = self.text[..self.cursor]
            .rfind('\n')
            .map(|index| index + 1)
            .unwrap_or(0);
    }

    pub fn move_end(&mut self) {
        self.cursor = self.text[self.cursor..]
            .find('\n')
            .map(|index| self.cursor + index)
            .unwrap_or(self.text.len());
    }

    pub fn backspace(&mut self) {
        let previous = self.previous_grapheme();
        if previous < self.cursor {
            self.text.replace_range(previous..self.cursor, "");
            self.cursor = previous;
        }
    }

    pub fn delete(&mut self) {
        if let Some(grapheme) = self.text[self.cursor..].graphemes(true).next() {
            let end = self.cursor + grapheme.len();
            self.text.replace_range(self.cursor..end, "");
        }
    }

    pub fn visual_cursor(&self, width: usize) -> (u16, u16) {
        let width = width.max(1);
        let mut row = 0_u16;
        let mut column = 0_usize;
        for grapheme in self.text[..self.cursor].graphemes(true) {
            if grapheme == "\n" {
                row = row.saturating_add(1);
                column = 0;
                continue;
            }
            let grapheme_width = UnicodeWidthStr::width(grapheme).max(1);
            if column + grapheme_width > width {
                row = row.saturating_add(1);
                column = 0;
            }
            column += grapheme_width;
            if column >= width {
                row = row.saturating_add(1);
                column = 0;
            }
        }
        (column as u16, row)
    }

    fn previous_grapheme(&self) -> usize {
        self.text[..self.cursor]
            .grapheme_indices(true)
            .next_back()
            .map(|(index, _)| index)
            .unwrap_or(0)
    }
}

#[cfg(test)]
mod tests {
    use super::Editor;

    #[test]
    fn edits_whole_graphemes() {
        let mut editor = Editor::default();
        editor.insert("a👩‍💻b");
        editor.move_left();
        editor.backspace();
        assert_eq!(editor.text(), "ab");
    }

    #[test]
    fn counts_wide_cells() {
        let mut editor = Editor::default();
        editor.insert("測試");
        assert_eq!(editor.visual_cursor(20), (4, 0));
    }

    #[test]
    fn completion_replaces_a_token_and_places_the_cursor_after_it() {
        let mut editor = Editor::default();
        editor.insert("open al tail");
        editor.move_left();
        editor.move_left();
        editor.move_left();
        editor.move_left();
        editor.move_left();
        editor.replace_range(5, 7, "alpha");
        assert_eq!(editor.text(), "open alpha tail");
        assert_eq!(editor.cursor(), 10);
    }
}
