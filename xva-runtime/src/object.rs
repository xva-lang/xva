mod field;
pub mod header;
pub mod method_table;
pub mod runtime_type;

use self::{
    field::{ObjectFieldDescriptor, ObjectFieldDescriptors},
    header::ObjectHeader,
};
use crate::error::RuntimeError;
use std::alloc::{alloc, Layout};
use std::mem::size_of;

const ALIGN_VALUE: usize = 8;

/// A Xva object that resides in the managed heap.
///
/// # Thread safety
/// Rust will automatically un-impl [`Send`](core::marker::Send) and
/// [`Sync`](core::marker::Sync) for one very good reason:
///
/// ### Sharing objects across threads is **not** thread-safe!
///
/// The structure of an object contains, among other things, a pointer into the managed Xva heap. Passing such
/// a pointer around is fine, but there are no guarantees when doing so between execution threads. If shared resources
/// is required between threads, userland must deal with it.
///
/// # Stability
/// This API is **unstable** and is therefore highly subject to change without warning.
///
// TODO let userland not just suck it up, and instead implement isolates for thread-safe shared resources.
#[repr(C)]
#[derive(Debug)]
pub struct Object {
    header: *const ObjectHeader,
    heap_region: *mut u8,
}

impl Object {
    /// Create a new Xva object.
    ///
    /// # Arguments
    /// `header` - An immutable pointer to an [`ObjectHeader`](self::header::ObjectHeader) that was previously
    /// allocated onto the heap.
    ///
    /// # Returns
    /// An `Object` instance, with it's internal heap pointer set to [`null`](std::ptr::null)
    pub fn new(header: *const ObjectHeader) -> Self {
        Self {
            header,
            heap_region: std::ptr::null_mut(),
        }
    }

    /// Allocates an existing object onto the heap, with space for itself plus the fields and methods described by
    /// its [`RuntimeType`](self::runtime_type::RuntimeType)
    ///
    /// # Returns
    /// A an `Ok` variant containing `()` if the heap allocation was successful, otherwise an `Err` variant
    /// containing a [`RuntimeError`] describing the allocation failure.
    pub fn heap_alloc(&mut self) -> Result<(), RuntimeError> {
        let header = unsafe {
            match self.header.as_ref() {
                Some(h) => h,
                None => {
                    return Err(RuntimeError::new(
                        "Null reference exception. Object header is a null pointer.",
                    ))
                }
            }
        };

        if let Some(runtime_type) = header.get_runtime_type_as_ref() {
            let field_size = runtime_type.get_fields_size();
            if field_size <= 0 {
                return Err(RuntimeError::new("Cannot allocate a zero-sized object"));
            } else {
                match Layout::from_size_align(size_of::<Object>() + field_size, ALIGN_VALUE) {
                    Ok(l) => {
                        self.heap_region = unsafe { alloc(l) };
                        Ok(())
                    }
                    Err(e) => Err(RuntimeError::new(e.to_string().as_str())),
                }
            }
        } else {
            return Err(RuntimeError::new(
                "Null reference exception. Runtime type is a null pointer.",
            ));
        }
    }

    #[inline]
    fn get_offset_into_heap_region(&self, field_index: usize) -> Result<isize, RuntimeError> {
        let previous_fields_offset: isize = if field_index == 0 {
            0
        } else {
            match self.get_field_descriptors() {
                Ok(fd) => fd
                    .iter()
                    .map(|d| d.get_size() as isize)
                    .take(field_index)
                    .sum(),
                Err(e) => {
                    return Err(RuntimeError::new(
                        format!("Failed to get object field descriptors: Inner error: {}", e)
                            .as_str(),
                    ))
                }
            }
        };

        Ok(previous_fields_offset)
    }

    #[inline]
    fn get_field_size(&self, field_index: usize) -> Result<usize, RuntimeError> {
        match self.get_field_descriptor_at(field_index) {
            Ok(d) => Ok(d.get_size()),
            Err(e) => Err(e),
        }
    }

    /// Sets the specified field to a value of type `T`.
    ///
    /// # Arguments
    /// `field_index` - The particular field to set, that must be defined in the object's
    /// [`RuntimeType`](self::runtime_type::RuntimeType)
    /// `value` - The value to set the field to
    /// # Safety
    /// This method only checks that the desired field has the same size (in bytes) to that of the type of
    /// the provided value. You must ensure that the correct field is being set, as if you have two types of
    /// the same size, the function will succeed but the values will be cast incorrectly.
    #[inline]
    pub fn set_field<T: Sized>(
        &mut self,
        field_index: usize,
        value: T,
    ) -> Result<(), RuntimeError> {
        let field_offset = match self.get_offset_into_heap_region(field_index) {
            Ok(f) => f,
            Err(e) => {
                return Err(RuntimeError::new(
                    format!("Error getting field offset. Inner error: {}", e).as_str(),
                ))
            }
        };

        match self.get_field_size(field_index) {
            Ok(fs) => {
                if fs != size_of::<T>() {
                    return Err(RuntimeError::new(
                        "Unsafe cast! Actual field size does not equal size of provided value",
                    ));
                }
            }
            Err(e) => {
                return Err(RuntimeError::new(
                    format!("Error getting field size. Inner error: {}", e).as_str(),
                ))
            }
        };

        unsafe {
            let field_ptr = self.heap_region.offset(field_offset) as *mut T;
            field_ptr.write(value);
        };

        Ok(())
    }

    /// Gets the value of the specified field and coerces it to type `T`.
    ///
    /// # Arguments
    /// `field_index` - The particular field to get, that must be defined in the object's
    /// [`RuntimeType`](self::runtime_type::RuntimeType)
    /// # Safety
    /// This method only checks that the desired field has the same size (in bytes) to that of the requested type.
    /// You must ensure that the correct field is being retrieved, as if you have two types of
    /// the same size, the type-coercion will succeed but the values will be cast incorrectly.
    pub fn get_field<T: Sized>(&self, field_index: usize) -> Result<T, RuntimeError> {
        let field_offset = match self.get_offset_into_heap_region(field_index) {
            Ok(f) => f,
            Err(e) => {
                return Err(RuntimeError::new(
                    format!("Error getting field offset. Inner error: {}", e).as_str(),
                ))
            }
        };

        match self.get_field_size(field_index) {
            Ok(fs) => {
                if fs != size_of::<T>() {
                    return Err(RuntimeError::new(
                        "Unsafe cast! Size of destination type does not equal size of object field.",
                    ));
                }
            }
            Err(e) => {
                return Err(RuntimeError::new(
                    format!("Error getting field size. Inner error: {}", e).as_str(),
                ))
            }
        };

        let val = unsafe {
            let field_ptr = self.heap_region.offset(field_offset) as *const T;
            println!("field_ptr: {:p}", field_ptr);
            field_ptr.read()
        };

        Ok(val)
    }

    fn get_field_descriptor_at(&self, index: usize) -> Result<ObjectFieldDescriptor, RuntimeError> {
        if let Some(header_ref) = unsafe { self.header.as_ref() } {
            header_ref.get_field_descriptor_at(index)
        } else {
            Err(RuntimeError::new(
                "Null reference exception. Object header is a null pointer.",
            ))
        }
    }

    fn get_field_descriptors(&self) -> Result<ObjectFieldDescriptors, RuntimeError> {
        if let Some(header_ref) = unsafe { self.header.as_ref() } {
            if let Some(rtti_ref) = header_ref.get_runtime_type_as_ref() {
                Ok(rtti_ref.get_field_pairs_as_vec())
            } else {
                Err(RuntimeError::new(
                    "Null reference exception. Runtime type is a null pointer.",
                ))
            }
        } else {
            Err(RuntimeError::new(
                "Null reference exception. Object header is a null pointer.",
            ))
        }
    }

    /// Casts the object to a raw pointer
    pub fn as_ptr(&self) -> ObjectPtr {
        self as ObjectPtr
    }

    /// Prints the address of the object itself, its header, and any fields that have been allocated to the heap.
    ///
    /// This function does nothing if `cfg(debug_assertions)` is off.
    pub fn debug_object(&self) {
        if cfg!(debug_assertions) {
            println!("Object @ {:p}", self.as_ptr());
            println!(
                "-> Header @ {:p} (size = {})",
                self.header,
                size_of::<*const ObjectHeader>()
            );
            match self.get_field_descriptors() {
                Ok(v) => {
                    for (i, _) in v.iter().enumerate() {
                        println!(
                            "->   Item @ {:p} + {:#04x}",
                            self.as_ptr(),
                            match self.get_offset_into_heap_region(i) {
                                Ok(p) => p,
                                Err(e) => panic!(
                                    "Failed to calculate object field offset. Inner error: {e}"
                                ),
                            }
                        )
                    }
                }
                Err(e) => panic!("{}", e),
            }
        }
    }
}

/// Convenience type alias for an immutable pointer to an `Object`.
pub type ObjectPtr = *const Object;

/// Convenience type alias for a mutable pointer to an `Object`.
pub type MutObjectPtr = *mut Object;

#[cfg(test)]
mod tests {
    use super::{
        method_table::{MethodTable, MethodTablePtr},
        runtime_type::{RuntimeType, RuntimeTypePtr},
        Object, ObjectHeader,
    };
    use std::mem::size_of;

    #[test]
    #[should_panic]
    fn invalid_object_field_request_out_of_bounds() {
        let method_table = MethodTable::new();
        let rtti = RuntimeType::new(&method_table as MethodTablePtr, vec![4, 8, 16]);
        let header = match ObjectHeader::new_on_heap(&rtti as *const RuntimeType) {
            Ok(h) => h,
            Err(e) => panic!("{}", e),
        };

        let object = Object::new(header);
        let _ = object.get_field_descriptor_at(3).unwrap();
    }

    #[test]
    fn object_set_and_get_field() {
        let method_table = MethodTable::new();
        let rtti = RuntimeType::new(method_table.as_ptr(), vec![4, 8, 16]);
        let header = match ObjectHeader::new_on_heap(&rtti as RuntimeTypePtr) {
            Ok(h) => h,
            Err(e) => panic!("{}", e),
        };

        let mut object = Object::new(header);

        match object.heap_alloc() {
            Ok(_) => {}
            Err(e) => panic!("{e}"),
        };

        const TEST_VALUE: u32 = 69u32;
        object.set_field(0, TEST_VALUE).unwrap();

        match object.get_field::<u32>(0) {
            Ok(v) => assert_eq!(v, TEST_VALUE),
            Err(e) => panic!("{}", e),
        }
    }
}
