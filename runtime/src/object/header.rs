use super::{field::ObjectFieldDescriptor, runtime_type::RuntimeType, ALIGN_VALUE};
use crate::error::RuntimeError;
use std::{
    alloc::{alloc, Layout},
    mem::size_of,
};

#[repr(C)]
#[derive(Debug)]
pub struct ObjectHeader {
    flags: usize,
    runtime_type: *const RuntimeType,
}

impl ObjectHeader {
    pub fn new_on_heap(runtime_type: *const RuntimeType) -> Result<*const Self, RuntimeError> {
        match Layout::from_size_align(size_of::<Self>(), ALIGN_VALUE) {
            Ok(l) => unsafe {
                let temp = alloc(l) as *mut Self;
                (*temp).runtime_type = runtime_type;
                Ok(temp as *const Self)
            },
            Err(e) => Err(RuntimeError::new(e.to_string().as_str())),
        }
    }

    pub(super) fn get_runtime_type_as_ref(&self) -> Option<&RuntimeType> {
        unsafe { self.runtime_type.as_ref() }
    }

    pub(super) fn get_field_descriptor_at(
        &self,
        index: usize,
    ) -> Result<ObjectFieldDescriptor, RuntimeError> {
        if let Some(runtime_type_ref) = unsafe { self.runtime_type.as_ref() } {
            match runtime_type_ref.get_field_descriptor_at(index) {
                Ok(r) => Ok(r),
                Err(e) => Err(e),
            }
        } else {
            Err(RuntimeError::new(
                "Null reference exception. Object header is a null pointer.",
            ))
        }
    }
}
