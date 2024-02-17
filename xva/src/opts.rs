use std::{collections::HashMap, error::Error};

use clap::Parser;
pub(super) fn parse_unstable_option<K>(
    s: &str,
) -> Result<(K, UnstableOptionKind), Box<dyn Error + Send + Sync + 'static>>
where
    K: std::str::FromStr,
    K::Err: Error + Send + Sync + 'static,
{
    if s.contains('=') {
        let pos = s
            .find('=')
            .ok_or_else(|| format!("Invalid KEY=value: no `=` found in `{}`", s))?;
        let comma_pos = s.find(',');
        if let Some(_) = comma_pos {
            Ok((
                s[..pos].parse()?,
                UnstableOptionKind::MultipleValues(
                    s[pos + 1..]
                        .split(",")
                        .into_iter()
                        .map(|x| x.trim().to_string())
                        .collect(),
                ),
            ))
        } else {
            Ok((
                s[..pos].parse()?,
                UnstableOptionKind::Value(s[pos + 1..].parse()?),
            ))
        }
    } else {
        Ok((s.parse()?, UnstableOptionKind::NoValue))
    }
}

#[derive(Debug, Clone)]
pub(super) enum UnstableOptionKind {
    NoValue,
    Value(String),
    MultipleValues(Vec<String>),
}

#[derive(Parser, Debug)]
pub(super) struct Options {
    /// Specify unstable compiler options
    #[arg(short = 'Z', value_parser = parse_unstable_option::<String>)]
    pub unstable_options: HashMap<String, UnstableOptionKind>,
}

impl Options {
    pub(crate) fn get_unstable(&self, key: &str) -> Option<&UnstableOptionKind> {
        self.unstable_options.get(key)
    }

    pub(crate) fn unstable_option_is(&self, key: &str, check: Option<&str>) -> bool {
        match self.unstable_options.get(key) {
            Some(v) => match v {
                UnstableOptionKind::NoValue => {
                    if let None = check {
                        true
                    } else {
                        false
                    }
                }
                UnstableOptionKind::Value(v) => {
                    if let Some(c) = check {
                        c == v
                    } else {
                        false
                    }
                }
                _ => false,
            },
            None => false,
        }
    }

    pub(crate) fn unstable_option_contains(&self, key: &str, check: &str) -> bool {
        match self.unstable_options.get(key) {
            Some(v) => match v {
                UnstableOptionKind::MultipleValues(v) => {
                    v.iter().map(|x| x.as_str()).find(|x| *x == check).is_some()
                }
                _ => false,
            },
            None => false,
        }
    }
}
