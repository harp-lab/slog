const VERSION_FILE: &str = include_str!(concat!(env!("CARGO_MANIFEST_DIR"), "/../.version"));

pub fn current() -> &'static str {
    VERSION_FILE.trim()
}

#[cfg(test)]
mod tests {
    use super::current;

    #[test]
    fn repository_version_is_numeric_semver() {
        let parts = current().split('.').collect::<Vec<_>>();
        assert_eq!(parts.len(), 3);
        assert!(
            parts
                .iter()
                .all(|part| !part.is_empty() && part.chars().all(|ch| ch.is_ascii_digit()))
        );
    }
}
