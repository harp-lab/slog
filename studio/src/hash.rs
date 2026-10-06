//! 64-bit FNV-1a, the content hash that names store objects.
//!
//! FNV is not collision-resistant against an adversary, and need not be: the
//! store holds one user's own files, and it compares content whenever an
//! object's name is already taken (`store.rs`), so an accidental collision is
//! reported rather than silently aliasing two files.

use serde::{Deserialize, Deserializer, Serialize, Serializer};
use std::fmt;

const OFFSET_BASIS: u64 = 0xcbf2_9ce4_8422_2325;
const PRIME: u64 = 0x0000_0100_0000_01b3;

/// A content hash, written as 16 lowercase hex digits.
#[derive(Clone, Copy, Debug, Eq, Hash, Ord, PartialEq, PartialOrd)]
pub struct Hash(u64);

impl Hash {
    pub fn of(bytes: &[u8]) -> Self {
        Self(bytes.iter().fold(OFFSET_BASIS, |hash, &byte| {
            (hash ^ u64::from(byte)).wrapping_mul(PRIME)
        }))
    }

    pub fn parse(hex: &str) -> Option<Self> {
        if hex.len() != 16
            || !hex
                .bytes()
                .all(|b| b.is_ascii_digit() || (b'a'..=b'f').contains(&b))
        {
            return None;
        }
        u64::from_str_radix(hex, 16).ok().map(Self)
    }
}

impl fmt::Display for Hash {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{:016x}", self.0)
    }
}

impl Serialize for Hash {
    fn serialize<S: Serializer>(&self, serializer: S) -> Result<S::Ok, S::Error> {
        serializer.collect_str(self)
    }
}

impl<'de> Deserialize<'de> for Hash {
    fn deserialize<D: Deserializer<'de>>(deserializer: D) -> Result<Self, D::Error> {
        let hex = String::deserialize(deserializer)?;
        Self::parse(&hex).ok_or_else(|| serde::de::Error::custom(format!("not a hash: {hex}")))
    }
}

#[cfg(test)]
mod tests {
    use super::Hash;

    /// Vectors from the FNV reference test suite (Noll, `test_fnv.c`).
    #[test]
    fn matches_the_reference_vectors() {
        assert_eq!(Hash::of(b"").to_string(), "cbf29ce484222325");
        assert_eq!(Hash::of(b"a").to_string(), "af63dc4c8601ec8c");
        assert_eq!(Hash::of(b"foobar").to_string(), "85944171f73967e8");
    }

    #[test]
    fn parses_only_what_it_prints() {
        let hash = Hash::of(b"rule (edge 1 2)");
        assert_eq!(Hash::parse(&hash.to_string()), Some(hash));
        assert_eq!(Hash::parse("CBF29CE484222325"), None);
        assert_eq!(Hash::parse("cbf29ce48422232"), None);
    }
}
