use super::opcode::Opcode;

#[derive(Debug, PartialEq)]
struct Instruction {
    opcode: Opcode,
}

impl Instruction {
    #[allow(dead_code)]
    pub(crate) fn new(opcode: Opcode) -> Self {
        Self { opcode }
    }
}

#[cfg(test)]
mod tests {
    use super::Instruction;
    use super::Opcode;

    #[test]
    fn create_instruction() {
        let inst = Instruction::new(Opcode::Halt);
        assert_eq!(inst.opcode, Opcode::Halt)
    }
}
