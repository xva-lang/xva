use std::alloc::{alloc, Layout};
use std::mem::size_of;

use crate::error::RuntimeError;

const ALIGN_VALUE: usize = 8;
const HEADER_SIZE: usize = 40;

/// A Xva object that resides in the managed heap.
#[repr(C)]
#[derive(Debug)]
pub struct Object {
    /// Reusable header information, such as flags.
    ///
    /// At offset zero from the object pointer.
    ///
    /// This property is unstable! Its usage may change in future iterations
    header: [u8; HEADER_SIZE],

    /// A `Vec` of `offset`, `size` values representing the size of the object's fields and their
    /// offsets relative to the object pointer.
    ///
    /// This means that the first field will always be at offset = `std::mem::size_of::<Object>()`. Do not rely
    /// on a constant value for the start of the fields, as the layout of `Object` may change
    field_ptrs: ObjectFieldPairs,
}

impl Object {
    pub fn new(field_ptrs: ObjectFieldPairs) -> Self {
        Self {
            header: [0; HEADER_SIZE],
            field_ptrs,
        }
    }

    pub fn heap_alloc(&self) -> Result<*const u8, RuntimeError> {
        let field_size: usize = self.field_ptrs.iter().map(|(_, size)| size).sum();
        if field_size <= 0 {
            return Err(RuntimeError::new("Cannot allocate a zero-sized object"));
        } else {
            match Layout::from_size_align(size_of::<Object>() + field_size, ALIGN_VALUE) {
                Ok(l) => Ok(unsafe { alloc(l) as *const u8 }),
                Err(e) => Err(RuntimeError::new(e.to_string().as_str())),
            }
        }
    }

    pub fn set_field<T: Sized>(
        &mut self,
        field_index: usize,
        value: T,
    ) -> Result<(), RuntimeError> {
        let (field_offset, field_size) = self.get_field_pair_at(field_index);
        if size_of::<T>() != *field_size {
            return Err(RuntimeError::new(
                "Size of value does not match size of defined object field",
            ));
        }

        let self_ptr = self as *const Self;
        let field_ptr = unsafe { self_ptr.offset(*field_offset as isize) as *mut T };
        unsafe { *field_ptr = value };

        Ok(())
    }

    pub fn get_field<T: Sized>(&self, field_index: usize) -> Result<T, RuntimeError> {
        let (field_offset, field_size) = self.get_field_pair_at(field_index);
        if size_of::<T>() != *field_size {
            return Err(RuntimeError::new(
                "Size of value does not match size of defined object field".into(),
            ));
        }

        let self_ptr = self as *const Self;
        let field_ptr = unsafe { self_ptr.offset(*field_offset as isize) as *const T };
        let val = unsafe { field_ptr.read() };

        Ok(val)
    }

    fn get_field_pair_at(&self, index: usize) -> &ObjectFieldPair {
        &self.field_ptrs[index]
    }
}

pub type ObjectPtr = *const Object;
pub type MutObjectPtr = *mut Object;
pub type ObjectFieldPairs = Vec<ObjectFieldPair>;
pub type ObjectFieldPair = (usize, usize);

#[cfg(test)]
mod tests {
    use super::Object;
    use std::mem::size_of;

    #[test]
    fn object() {
        let mut object = Object::new(vec![(0, size_of::<i32>())]);
        let _ = match object.heap_alloc() {
            Ok(p) => p,
            Err(e) => panic!("{}", e),
        };

        match object.set_field(0, 69i32) {
            Ok(_) => {}
            Err(e) => panic!("{}", e),
        };

        match object.get_field::<i32>(0) {
            Ok(v) => assert_eq!(v, 69i32),
            Err(e) => panic!("{}", e),
        }
    }
}
