mod error;
mod object;
mod value;
mod operator;

pub use crate::{
    error::RuntimeError,
    object::{
        header::ObjectHeader,
        method_table::{MethodTable, MethodTablePtr},
        runtime_type::{RuntimeType, RuntimeTypePtr},
        MutObjectPtr, Object, ObjectPtr,
    },
};
