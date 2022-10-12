pub struct IStream {
    pub instructions: Box<Vec<u8>>,
    pub instruction_pointer: usize,
    pub stream_size: usize,
}

impl IStream {
    pub fn get_vec_ref(&self) -> &Vec<u8> {
        &self.instructions
    }

    pub fn read_uint8(&self) -> u8 {
        let vec_ref = &self.instructions;
        let ip_ref = &self.instruction_pointer;
        match vec_ref.get(*ip_ref) {
            Some(val) => *(val),
            None => 0,
        }
    }

    pub fn read_uint16(&mut self) -> u16 {
        let mut values: [u8; 2] = [0, 0];
        values[1] = self.read_uint8();
        self.increment_instruction_pointer();
        values[0] = self.read_uint8();
        self.increment_instruction_pointer();

        super::stack::combine_bytes_u16(values)
    }

    pub fn read_uint32(&mut self) -> u32 {
        let mut values: [u8; 4] = [0, 0, 0, 0];

        values[0] = self.read_uint8();
        self.increment_instruction_pointer();
        for i in 1..4 {
            values[i] = self.read_uint8();
            self.increment_instruction_pointer();
        }
        super::stack::combine_bytes_u32(values)
    }

    // pub fn read_uint64(&mut self) -> u64 {
    //     let mut values: [u8; 8] = [0; 8];

    //     values[0] = self.read_uint8();
    //     for i in 1..8 {
    //         self.increment_instruction_pointer();
    //         values[i] = self.read_uint8();
    //     }
    //     super::stack::combine_bytes_u64(values)
    // }

    // pub fn read_int8(&self) -> i8 {
    //     let vec_ref = &self.instructions;
    //     let ip_ref = &self.instruction_pointer;
    //     match vec_ref.get(*ip_ref) {
    //         Some(val) => *(val) as i8,
    //         None => 0,
    //     }
    // }

    pub fn read_string(&mut self, size: usize, machine: &super::Machine) -> String {
        let mut byte_vec: Vec<u8> = vec![];

        //     let buf = &[0x41u8, 0x41u8, 0x42u8];
        // let s = String::from_utf8_lossy(buf);
        // println!("result: {}", s);

        for _ in 0..size {
            byte_vec.push(self.read_uint8());
            self.increment_instruction_pointer();
        }

        match String::from_utf8(byte_vec) {
            Ok(val) => val,
            Err(_) => {
                machine.panic("Failed to read a string from the instruction stream");
                String::from("")
            }
        }
    }

    pub fn increment_instruction_pointer(&mut self) {
        self.instruction_pointer += 1;
    }

    pub fn decrement_instruction_pointer(&mut self) {
        self.instruction_pointer -= 1;
    }
}

pub fn from_file(file_name: &str) -> IStream {
    let instructions = match std::fs::read(file_name) {
        Ok(result) => result,
        Err(_) => {
            println!("failed to read the file");
            std::process::exit(-1);
        }
    };

    let stream_size = instructions.len();
    IStream {
        instructions: Box::from(instructions),
        instruction_pointer: 0,
        stream_size: stream_size,
    }
}
