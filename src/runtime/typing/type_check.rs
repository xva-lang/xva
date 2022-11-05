pub trait TypeCheck<TCheck, TValue> {
    fn type_check(check_type: TCheck, input: TValue) -> bool;
}
