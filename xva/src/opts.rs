use std::error::Error;

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
        Ok((
            s[..pos].parse()?,
            UnstableOptionKind::WithValue(s[pos + 1..].parse()?),
        ))
    } else {
        Ok((s.parse()?, UnstableOptionKind::NoValue))
    }
}

#[derive(Debug, Clone)]
pub(super) enum UnstableOptionKind {
    NoValue,
    WithValue(String),
}

#[derive(Parser, Debug)]
pub(super) struct Options {
    /// Specify unstable compiler options
    #[arg(short = 'Z', value_parser = parse_unstable_option::<String>)]
    pub unstable_options: Vec<(String, UnstableOptionKind)>,
}
