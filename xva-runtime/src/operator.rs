use crate::value::Value;

trait ArithmeticOperator {
    fn precedence(&self) -> u8; // TODO: Use a type for precedence
    // fn associativity(&self) -> Associativity; TODO
    fn eval(&self, lhs: Value, rhs: Value) -> Value;
}

struct AdditionOperator;

impl ArithmeticOperator for AdditionOperator {
    fn eval(&self, lhs: Value, rhs: Value) -> Value {

        // TODO: Should do this recursively but I'm feeling lazy

        match (lhs, rhs) {
            (Value::Int(lhs), Value::Int(rhs)) => Value::Int(lhs + rhs),
            (Value::Float(lhs), Value::Float(rhs)) => Value::Float(lhs + rhs),
            (Value::Int(lhs), Value::Float(rhs)) => Value::Float(lhs as f32 + rhs),
            (Value::Float(lhs), Value::Int(rhs)) => Value::Float(lhs + rhs as f32),
            (Value::Long(lhs), Value::Long(rhs)) => Value::Long(lhs + rhs),
            (Value::Double(lhs), Value::Double(rhs)) => Value::Double(lhs + rhs),
            (Value::Long(lhs), Value::Double(rhs)) => Value::Double(lhs as f64 + rhs),
            (Value::Double(lhs), Value::Long(rhs)) => Value::Double(lhs + rhs as f64),
            _ => panic!("Invalid operands for addition operator"),
        }
    }

    fn precedence(&self) -> u8 {
        todo!()
    }
}