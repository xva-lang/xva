use std::rc::Rc;

pub trait XvaObject {
    fn new() -> Rc<Self>;
}

pub struct UInt8 {}

impl XvaObject for UInt8 {
    fn new() -> Rc<Self> {
        todo!()
    }
}
