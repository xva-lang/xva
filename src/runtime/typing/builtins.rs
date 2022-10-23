#[derive(Clone)]
pub enum Type {
    Void,
    Integer(i64),
    Float(f64),
    Boolean(bool),
    Char(char),
}
