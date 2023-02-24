#[derive(Clone)]
pub enum Value {
    Unit,
    Boolean(bool),
    Byte(u8),
    SignedByte(i8),
    Short(u16),
    SignedShort(i16),
    Int(u32),
    SignedInt(i32),
    Long(u64),
    SignedLong(i64),
    Float(f32),
    Double(f64),
    Char(char),
    Pointer(*const u8),
}

#[cfg(test)]
mod tests {
    use std::alloc::Layout;

    fn layout_from_size(size: usize) -> Layout {
        match Layout::from_size_align(size, 8) {
            Ok(l) => l,
            Err(e) => panic!("{}", e),
        }
    }
    #[test]
    fn tests() {
        #[repr(C)]
        #[derive(Debug)]
        struct Object {
            // offset 0
            header: [u8; 40],

            // offset 8
            /// (offset, size)
            field_ptrs: Vec<(usize, usize)>,
            // fields start at offset 32
        }

        let object_size = std::mem::size_of::<Object>() + 8; // object + two u32's
        let object_ptr = unsafe {
            std::alloc::alloc(
                Layout::from_size_align(object_size, std::mem::size_of::<usize>()).unwrap(),
            ) as *mut Object
        };

        unsafe {
            let field_two = object_ptr.offset(4) as *mut u32;
            *field_two = 69;
        }

        unsafe {
            println!("{:#?}", *object_ptr);
            println!("{}", *(object_ptr.offset(4) as *mut u32))
        }
    }
}
