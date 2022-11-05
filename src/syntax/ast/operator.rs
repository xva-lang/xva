pub(crate) trait BindingPowered {
    /// Determines the left and right binding powers for a given operator.
    /// # Returns
    /// A tuple containing a `Some(u8)` and a `u8` representing the left and right binding powers, respectively. If an
    /// operator does not bind left (prefixes, for instance) then the return value is `(None, u8)`.
    fn binding_power(&self) -> (Option<u8>, u8);
}

#[derive(Debug, Clone)]
pub(crate) enum InfixOperator {
    Addition,
    Subtraction,
    Multiplication,
    Division,
}

impl std::fmt::Display for InfixOperator {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "{}",
            match self {
                InfixOperator::Addition => "+",
                InfixOperator::Subtraction => "-",
                InfixOperator::Multiplication => "*",
                InfixOperator::Division => "/",
            }
        )
    }
}

#[derive(Debug, Clone)]
pub(crate) enum PrefixOperator {
    Negation,
}

impl std::fmt::Display for PrefixOperator {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            PrefixOperator::Negation => write!(f, "-"),
        }
    }
}

const ADDITION_BINDING_POWER: u8 = 1;
const SUBTRACTION_BINDING_POWER: u8 = 2;
const MULTUPLICATION_BINDING_POWER: u8 = 3;
const DIVISION_BINDING_POWER: u8 = 4;
const NEGATION_BINDING_POWER: u8 = 5;

impl BindingPowered for InfixOperator {
    fn binding_power(&self) -> (Option<u8>, u8) {
        // 1 + 2 + 3 + 4
        // -> ((1 + 2) + 3) + 4
        // 1   +   2   +   3   +   4    <- item
        //   1   2   1   2   1   2      <- binding power
        match self {
            Self::Addition | Self::Subtraction => {
                (Some(ADDITION_BINDING_POWER), SUBTRACTION_BINDING_POWER)
            }
            Self::Multiplication | Self::Division => {
                (Some(MULTUPLICATION_BINDING_POWER), DIVISION_BINDING_POWER)
            }
        }
    }
}

impl BindingPowered for PrefixOperator {
    fn binding_power(&self) -> (Option<u8>, u8) {
        match self {
            PrefixOperator::Negation => (None, NEGATION_BINDING_POWER),
        }
    }
}
