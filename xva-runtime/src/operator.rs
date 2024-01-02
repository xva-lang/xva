use crate::value::Value;
use crate::associativity::Associativity;

// Copying precedence and associativity tables used in C++
// https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B#Operator_precedence
trait ArithmeticOperator {
    fn get_precedence(&self) -> usize; 
    fn get_associativity(&self) -> Associativity;
    fn eval(&self, lhs: Value, rhs: Value) -> Value;
}


struct AdditionOperator;

impl ArithmeticOperator for AdditionOperator {
    
    fn get_precedence(&self) -> usize {
        return 6;
    }

    fn get_associativity(&self) -> Associativity {
        return Associativity::Left;
    }
    
    fn eval(&self, lhs: Value, rhs: Value) -> Value {
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
}


struct SubtractionOperator;

impl ArithmeticOperator for SubtractionOperator {
    
    fn get_precedence(&self) -> usize {
        return 6;
    }
    
    fn get_associativity(&self) -> Associativity {
        return Associativity::Left.clone().clone();
    }
    
    fn eval(&self, lhs: Value, rhs: Value) -> Value {
        match (lhs, rhs) {
            (Value::Int(lhs), Value::Int(rhs)) => Value::Int(lhs - rhs),
            (Value::Float(lhs), Value::Float(rhs)) => Value::Float(lhs - rhs),
            (Value::Int(lhs), Value::Float(rhs)) => Value::Float(lhs as f32 - rhs),
            (Value::Float(lhs), Value::Int(rhs)) => Value::Float(lhs - rhs as f32),
            (Value::Long(lhs), Value::Long(rhs)) => Value::Long(lhs - rhs),
            (Value::Double(lhs), Value::Double(rhs)) => Value::Double(lhs - rhs),
            (Value::Long(lhs), Value::Double(rhs)) => Value::Double(lhs as f64 - rhs),
            (Value::Double(lhs), Value::Long(rhs)) => Value::Double(lhs - rhs as f64),
            _ => panic!("(Invalid operands for subtraction operator"),
        }
    }
}


struct MultiplicationOperator;

impl ArithmeticOperator for MultiplicationOperator {
    
    fn get_precedence(&self) -> usize {
        return 5;
    }
    
    fn get_associativity(&self) -> Associativity {
        return Associativity::Left.clone();
    }

    fn eval(&self, lhs: Value, rhs: Value) -> Value {
        match (lhs, rhs) {
            (Value::Int(lhs), Value::Int(rhs)) => Value::Int(lhs * rhs),
            (Value::Float(lhs), Value::Float(rhs)) => Value::Float(lhs * rhs),
            (Value::Int(lhs), Value::Float(rhs)) => Value::Float(lhs as f32 * rhs),
            (Value::Float(lhs), Value::Int(rhs)) => Value::Float(lhs * rhs as f32),
            (Value::Long(lhs), Value::Long(rhs)) => Value::Long(lhs * rhs),
            (Value::Double(lhs), Value::Double(rhs)) => Value::Double(lhs * rhs),
            (Value::Long(lhs), Value::Double(rhs)) => Value::Double(lhs as f64 * rhs),
            (Value::Double(lhs), Value::Long(rhs)) => Value::Double(lhs * rhs as f64),
            _ => panic!("Invalid operands for multiplication operator"),
        }
    }
}


struct DivisionOperator;

impl ArithmeticOperator for DivisionOperator {
    
    fn get_precedence(&self) -> usize {
        return 5;
    }
    
    fn get_associativity(&self) -> Associativity {
        return Associativity::Left.clone();
    }
    
    fn eval(&self, lhs: Value, rhs: Value) -> Value {
        match (lhs, rhs) {
            (Value::Int(lhs), Value::Int(rhs)) => Value::Int(lhs / rhs),
            (Value::Float(lhs), Value::Float(rhs)) => Value::Float(lhs / rhs),
            (Value::Int(lhs), Value::Float(rhs)) => Value::Float(lhs as f32 / rhs),
            (Value::Float(lhs), Value::Int(rhs)) => Value::Float(lhs / rhs as f32),
            (Value::Long(lhs), Value::Long(rhs)) => Value::Long(lhs / rhs),
            (Value::Double(lhs), Value::Double(rhs)) => Value::Double(lhs / rhs),
            (Value::Long(lhs), Value::Double(rhs)) => Value::Double(lhs as f64 / rhs),
            (Value::Double(lhs), Value::Long(rhs)) => Value::Double(lhs / rhs as f64),
            _ => panic!("Invalid operands for division operator"),
        }
    }
}


struct ExponentiationOperator;

impl ArithmeticOperator for ExponentiationOperator {

    fn get_precedence(&self) -> usize {
        return 4;
    }
    
    fn get_associativity(&self) -> Associativity {
        return Associativity::Right.clone();
    }

    fn eval(&self, lhs: Value, rhs: Value) -> Value {
        match (lhs, rhs) {
            (Value::Int(lhs), Value::Int(rhs)) => Value::Int(lhs.pow(rhs as u32)),
            (Value::Float(lhs), Value::Float(rhs)) => Value::Float(lhs.powf(rhs)),
            (Value::Int(lhs), Value::Float(rhs)) => Value::Float((lhs as f32).powf(rhs)),
            (Value::Float(lhs), Value::Int(rhs)) => Value::Float(lhs.powf(rhs as f32)),
            (Value::Long(lhs), Value::Long(rhs)) => Value::Long(lhs.pow(rhs as u32)),
            (Value::Double(lhs), Value::Double(rhs)) => Value::Double(lhs.powf(rhs)),
            (Value::Long(lhs), Value::Double(rhs)) => Value::Double((lhs as f64).powf(rhs)),
            (Value::Double(lhs), Value::Long(rhs)) => Value::Double(lhs.powf(rhs as f64)),
            _ => panic!("Invalid operands for exponentiation operator"),
        }
    }
}


struct ModuloOperator;

impl ArithmeticOperator for ModuloOperator {

    fn get_precedence(&self) -> usize {
        return 5;
    }
    
    fn get_associativity(&self) -> Associativity {
        return Associativity::Left;
    }

    fn eval(&self, lhs: Value, rhs: Value) -> Value {
        match (lhs, rhs) {
            (Value::Int(lhs), Value::Int(rhs)) => Value::Int(lhs % rhs),
            (Value::Float(lhs), Value::Float(rhs)) => Value::Float(lhs % rhs),
            (Value::Int(lhs), Value::Float(rhs)) => Value::Float(lhs as f32 % rhs),
            (Value::Float(lhs), Value::Int(rhs)) => Value::Float(lhs % rhs as f32),
            (Value::Long(lhs), Value::Long(rhs)) => Value::Long(lhs % rhs),
            (Value::Double(lhs), Value::Double(rhs)) => Value::Double(lhs % rhs),
            (Value::Long(lhs), Value::Double(rhs)) => Value::Double(lhs as f64 % rhs),
            (Value::Double(lhs), Value::Long(rhs)) => Value::Double(lhs % rhs as f64),
            _ => panic!("Invalid operands for modulo operator"),
        }
    }
}