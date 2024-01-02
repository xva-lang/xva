use super::{
    field::ObjectFieldDescriptors, method_table::MethodTablePtr, ObjectFieldDescriptor, ALIGN_VALUE,
};
use crate::error::RuntimeError;
use std::{
    alloc::{alloc, Layout},
    mem::size_of,
};

/// An alias for an immutable pointer to a `RuntimeType`
pub type RuntimeTypePtr = *const RuntimeType;

/// Represents an object's type at runtime, enabling both "peek" and "poke" for
/// viewing/modifying object fields, and for runtime reflection capabilities.
///
/// # Stability
/// This API is **unstable** and is therefore highly subject to change without warning.
#[repr(C)]
#[derive(Debug)]
pub struct RuntimeType {
    method_table: MethodTablePtr,
    fields: Vec<usize>,
}

impl RuntimeType {
    pub fn new(method_table: MethodTablePtr, fields: Vec<usize>) -> Self {
        Self {
            method_table,
            fields,
        }
    }

    pub fn new_on_heap(
        method_table: MethodTablePtr,
        fields: Vec<usize>,
    ) -> Result<RuntimeTypePtr, RuntimeError> {
        match Layout::from_size_align(size_of::<Self>(), ALIGN_VALUE) {
            Ok(l) => unsafe {
                let temp = alloc(l) as *mut Self;
                (*temp).fields = fields;
                (*temp).method_table = method_table;
                Ok(temp as RuntimeTypePtr)
            },
            Err(e) => Err(RuntimeError::new(
                format!("Failed to allocate RuntimeType: Inner error: {}", e).as_str(),
            )),
        }
    }

    pub(super) fn get_field_descriptor_at(
        &self,
        index: usize,
    ) -> Result<ObjectFieldDescriptor, RuntimeError> {
        if index > (self.fields.len() - 1) {
            Err(RuntimeError::new("Object field was requested for an index outside the bounds of the object's fields."))
        } else {
            Ok(ObjectFieldDescriptor::new(self.fields[index]))
        }
    }

    pub(super) fn get_fields_size(&self) -> usize {
        self.fields.iter().sum()
    }

    pub(super) fn get_field_pairs_as_vec(&self) -> ObjectFieldDescriptors {
        self.fields
            .iter()
            .enumerate()
            .map(|(_, size)| ObjectFieldDescriptor::new(*size))
            .collect()
    }
}
