use std::{borrow::Borrow, sync::Arc};

use super::{LineEnding, SourceFile, SourceMap, SrcId};

impl<'map> codespan_reporting::files::Files<'map> for SourceMap<'map> {
    type FileId = SrcId;
    type Name = String;
    type Source = Arc<str>;

    fn name(&'map self, id: Self::FileId) -> Result<Self::Name, codespan_reporting::files::Error> {
        match self.get(id) {
            Some(f) => Ok(f.as_ref().name.clone()),
            None => Err(codespan_reporting::files::Error::FileMissing),
        }
    }

    fn source(
        &'map self,
        id: Self::FileId,
    ) -> Result<Self::Source, codespan_reporting::files::Error> {
        match self.get(id) {
            Some(f) => Ok(f.clone().content()),
            None => Err(codespan_reporting::files::Error::FileMissing),
        }
    }

    fn line_index(
        &'map self,
        id: Self::FileId,
        byte_index: usize,
    ) -> Result<usize, codespan_reporting::files::Error> {
        match self.get(id) {
            Some(f) => match f.line_ranges.keys().find(|x| x.contains(&byte_index)) {
                Some(m) => match f.line_ranges.get(m) {
                    Some(l) => Ok(*l),
                    None => unreachable!(),
                },
                None => unreachable!(),
            },

            None => Err(codespan_reporting::files::Error::FileMissing),
        }
    }

    fn line_range(
        &'map self,
        id: Self::FileId,
        line_index: usize,
    ) -> Result<std::ops::Range<usize>, codespan_reporting::files::Error> {
        match self.get(id) {
            Some(f) => {
                for (k, v) in f.line_ranges.iter() {
                    if *v == line_index {
                        return Ok(k.clone());
                    }
                }

                unreachable!()
            }

            None => Err(codespan_reporting::files::Error::FileMissing),
        }
    }
}
